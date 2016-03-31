# $NetBSD: Makefile,v 1.5 2014/11/27 10:35:46 fhajny Exp $
# requires GNU make

DEST=$(DESTDIR)$(PREFIX)

package:
	$(BSD_INSTALL_PROGRAM_DIR) ${DEST}/sbin
	sed "/RIAK_VERSION/s/git/${VERSIONSTRING}/" ${RIAK_PATH}/rel/riak/bin/riak \
	  > ${RIAK_PATH}/rel/riak/bin/riak.tmp
	$(BSD_INSTALL_SCRIPT) ${RIAK_PATH}/rel/riak/bin/riak.tmp ${DEST}/sbin/riak
	$(BSD_INSTALL_SCRIPT) ${RIAK_PATH}/rel/riak/bin/riak-admin ${DEST}/sbin
	$(BSD_INSTALL_SCRIPT) ${RIAK_PATH}/rel/riak/bin/riak-debug ${DEST}/sbin
	$(BSD_INSTALL_SCRIPT) ${RIAK_PATH}/rel/riak/bin/search-cmd ${DEST}/sbin
	$(BSD_INSTALL_MAN_DIR) ${DEST}/$(PKGMANDIR)/man1
	$(BSD_INSTALL_MAN) ${RIAK_PATH}/doc/man/man1/riak.1.gz ${DEST}/$(PKGMANDIR)/man1
	$(BSD_INSTALL_MAN) ${RIAK_PATH}/doc/man/man1/riak-admin.1.gz ${DEST}/$(PKGMANDIR)/man1
	$(BSD_INSTALL_MAN) ${RIAK_PATH}/doc/man/man1/riak-debug.1.gz ${DEST}/$(PKGMANDIR)/man1
	$(BSD_INSTALL_MAN) ${RIAK_PATH}/doc/man/man1/search-cmd.1.gz ${DEST}/$(PKGMANDIR)/man1
	$(BSD_INSTALL_DATA_DIR) ${DEST}/share/examples/riak
	$(BSD_INSTALL_DATA) ${RIAK_PATH}/rel/riak/etc/riak.conf ${DEST}/share/examples/riak
	$(BSD_INSTALL_DATA) ${RIAK_PATH}/rel/riak/etc/solr-log4j.properties ${DEST}/share/examples/riak
	$(BSD_INSTALL_PROGRAM_DIR) ${DEST}/lib/riak
	cp -Rp ${RIAK_PATH}/rel/riak/erts* ${DEST}/lib/riak
	cp -Rp ${RIAK_PATH}/rel/riak/lib ${DEST}/lib/riak
	cp -Rp ${RIAK_PATH}/rel/riak/releases ${DEST}/lib/riak
