---
tittle: homepage
name: hget
  Description: retrieve a web page corresponding to a url
---
  
SYNOPSIS
hget [ –dhv ] [ –o ofile ] [ –p body ] [ –x netmntpt ] [ –r header ] url

DESCRIPTION:

>
Hget retrieves the web page specified by the URL url and writes it, absent the –o option, to standard output. The known URL types are: http and ftp.
If url is of type HTTP and the –p option is specified, then an HTTP POST is performed with body as the data to be posted.

The –o option is used to keep a local file in sync with a web page. If the web page has been modified later than the file, it is copied into the file. If the file is up to date but incomplete, hget will fetch the missing bytes.

Option –h causes HTTP headers to be printed to standard output in addition to the transferred web page.

Option –r sends an arbitrary HTTP header.

Option –d turns on debugging written to standard error.

Normally, hget uses the IP stack mounted under /net. The –x option can be used to specify the mount point of a different IP stack to use.

Option
	/sys/src/cmd/hget.c
