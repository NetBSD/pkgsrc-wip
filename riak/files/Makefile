# $NetBSD: Makefile,v 1.2 2012/01/23 14:04:25 fhajny Exp $
# requires GNU make

DEST=$(DESTDIR)$(PREFIX)

build:
	$(BSD_INSTALL_PROGRAM_DIR) ${DEST}/sbin
	$(BSD_INSTALL_SCRIPT) ${RIAK_PATH}/rel/riak/bin/riak ${DEST}/sbin
	$(BSD_INSTALL_SCRIPT) ${RIAK_PATH}/rel/riak/bin/riak-admin ${DEST}/sbin
	$(BSD_INSTALL_SCRIPT) ${RIAK_PATH}/rel/riak/bin/search-cmd ${DEST}/sbin
	$(BSD_INSTALL_DATA_DIR) ${DEST}/share/examples/riak
	$(BSD_INSTALL_DATA) ${RIAK_PATH}/rel/riak/etc/app.config ${DEST}/share/examples/riak
	$(BSD_INSTALL_DATA) ${RIAK_PATH}/rel/riak/etc/vm.args ${DEST}/share/examples/riak
	$(BSD_INSTALL_PROGRAM_DIR) ${DEST}/riak
	cp -Rp ${RIAK_PATH}/rel/riak/erts* ${DEST}/riak
	cp -Rp ${RIAK_PATH}/rel/riak/lib ${DEST}/riak
	cp -Rp ${RIAK_PATH}/rel/riak/releases ${DEST}/riak
