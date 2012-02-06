# $NetBSD: Makefile,v 1.3 2012/02/06 12:41:36 fhajny Exp $
# requires GNU make

DEST=$(DESTDIR)$(PREFIX)

build:
	$(BSD_INSTALL_PROGRAM_DIR) ${DEST}/sbin
	sed "/RIAK_VERSION/s/git/${VERSIONSTRING}/" ${RIAK_PATH}/rel/riak/bin/riak \
	  > ${RIAK_PATH}/rel/riak/bin/riak.tmp
	$(BSD_INSTALL_SCRIPT) ${RIAK_PATH}/rel/riak/bin/riak.tmp ${DEST}/sbin/riak
	$(BSD_INSTALL_SCRIPT) ${RIAK_PATH}/rel/riak/bin/riak-admin ${DEST}/sbin
	$(BSD_INSTALL_SCRIPT) ${RIAK_PATH}/rel/riak/bin/search-cmd ${DEST}/sbin
	$(BSD_INSTALL_MAN_DIR) ${DEST}/$(PKGMANDIR)/man1
	$(BSD_INSTALL_MAN) ${RIAK_PATH}/doc/man/man1/riak.1.gz ${DEST}/$(PKGMANDIR)/man1
	$(BSD_INSTALL_MAN) ${RIAK_PATH}/doc/man/man1/riak-admin.1.gz ${DEST}/$(PKGMANDIR)/man1
	$(BSD_INSTALL_MAN) ${RIAK_PATH}/doc/man/man1/search-cmd.1.gz ${DEST}/$(PKGMANDIR)/man1
	$(BSD_INSTALL_DATA_DIR) ${DEST}/share/examples/riak
	$(BSD_INSTALL_DATA) ${RIAK_PATH}/rel/riak/etc/app.config ${DEST}/share/examples/riak
	$(BSD_INSTALL_DATA) ${RIAK_PATH}/rel/riak/etc/vm.args ${DEST}/share/examples/riak
	$(BSD_INSTALL_PROGRAM_DIR) ${DEST}/riak
	cp -Rp ${RIAK_PATH}/rel/riak/erts* ${DEST}/riak
	cp -Rp ${RIAK_PATH}/rel/riak/lib ${DEST}/riak
	cp -Rp ${RIAK_PATH}/rel/riak/releases ${DEST}/riak
