#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../data.h"
#include "../http.h"
#include "../util.h"

int
main(void)
{
	const char *names[] = { "javascript:alert(1)", "hash#part", "query?part",
	                      "percent%2e", "two words", "quote\"&<", "safe-._~" };
	const char *hrefs[] = { "javascript%3Aalert%281%29", "hash%23part", "query%3Fpart",
	                      "percent%252e", "two%20words", "quote%22%26%3C", "safe-._~" };
	char dir[] = "/tmp/quark-listing-test-XXXXXX", filename[PATH_MAX], expected[512];
	struct response res = {0};
	struct buffer buf = {0};
	size_t i, progress = 0;
	int fd, failed = 0;

	assert(mkdtemp(dir));
	for (i = 0; i < LEN(names); i++) {
		snprintf(filename, sizeof filename, "%s/%s", dir, names[i]);
		assert((fd = open(filename, O_WRONLY | O_CREAT | O_EXCL, 0600)) >= 0);
		close(fd);
	}
	snprintf(res.internal_path, sizeof res.internal_path, "%s", dir);
	snprintf(res.path, sizeof res.path, "/");
	assert(data_prepare_dirlisting_buf(&res, &buf, &progress) == 0);
	for (i = 0; i < LEN(names); i++) {
		snprintf(expected, sizeof expected, "href=\"%s\"", hrefs[i]);
		if (!strstr(buf.data, expected)) {
			fprintf(stderr, "missing safe URL: %s\n", expected);
			failed = 1;
		}
		snprintf(filename, sizeof filename, "%s/%s", dir, names[i]);
		assert(unlink(filename) == 0);
	}
	assert(strstr(buf.data, ">quote&quot;&amp;&lt;</a>"));
	assert(rmdir(dir) == 0);
	return failed;
}
