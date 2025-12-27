Webcookies reads cookiefile (default $home/lib/webcookies) and mounts itself at mtpt (default /mnt/webcookies). If service is specified, cookiefs will post a service file descriptor in /srv/service.

The cookie file contains one cookie per line; each cookie comprises some number of attr=value pairs. Cookie attributes are:

name=name      The name of the cookie on the remote server.
value=value     The value associated with that name on the remote server. The actual data included when a cookie is sent back to the server is ``name=value'' (where, confusingly, name and value are the values associated with the name and value attributes.
domain=domain   The domain within which the cookie can be used. If domain is an IP address, the cookie can only be used when connecting to a web server at that IP address. If domain is a pattern beginning with a dot, the cookie can only be used for servers whose name has domain as a suffix. For example, a
cookie with domain=.bell–labs.com may be used on the web sites www.bell–labs.com and www.research.bell–labs.com.
path=path       The cookie can only be used for URLs with a path (the part after http://hostname) beginning with path.
version=versionThe version of the HTTP cookie specification, specified by the server.
comment=comment
A comment, specified by the server.
expire=expire    The cookie expires at time expire, which is a decimal number of seconds since the epoch.
secure=1       The cookie may only be used over secure (https) connections.
explicitdomain=1
The domain associated with this cookie was set by the server (rather than inferred from a URL).
explicitpath=1
The path associated with this cookie was set by the server (rather than inferred from a URL).
netscapestyle=1
The server presented the cookie in ``Netscape style,'' which does not conform to the cookie standard, RFC2109. It is assumed that when presenting the cookie to the server, it must be sent back in Netscape style as well.
Webcookies serves a directory containing two files. The first, cookies, is a textual representation of the cookie file, which can be edited to change the set of cookies currently held. The second, http, is intended to be used by HTTP clients to access cookies. Upon opening http, the client must write a full URL to it. After writing the URL, reading from the file will yield any HTTP Cookie: headers that should be included in the request for this particular URL. Once the request has been made, any Set–Cookie: lines in the HTTP response header should be written to the file to save them for next time. If cookiefs decides not to accept the cookie (as outlined in RFC2109, section 4.3.4), no indication is given.

Hget(1) uses /mnt/webcookies/http, when it exists, to manage cookie state. Webfs does not (yet).

SOURCE
/sys/src/cmd/webcookies.c

SEE ALSO
hget(1)
