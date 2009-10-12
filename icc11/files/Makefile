linux:

netbsd: redefine-syms libicc11bsd.a

.PHONY: redefine-syms

redefine-syms:
	find icc11/lib -name *.a -exec objcopy \
		--redefine-sym __errno_location=__errno \
		--redefine-sym __assert_fail=__assertion_failed \
		{} \;

libicc11bsd.a: icc11bsd.o
	ar r libicc11bsd.a icc11bsd.o && \
		objcopy --redefine-sym my_stderr=stderr libicc11bsd.a

icc11bsd.o: icc11bsd.c
	cc icc11bsd.c -c -o icc11bsd.o

install-linux:  ins-common ins-so
install-netbsd: ins-common ins-bsd

ins-common: ins-man ins-doc ins-examples ins-lib ins-misc ins-include

ins-man:
	install -m 755 -d ${PREFIX}/${PKGMANDIR}/man1
	install -m 644 icc11/man/en_US/man1/codecov_c.1 ${PREFIX}/${PKGMANDIR}/man1
	install -m 644 icc11/man/en_US/man1/icc.1       ${PREFIX}/${PKGMANDIR}/man1
	install -m 644 icc11/man/en_US/man1/icpc.1      ${PREFIX}/${PKGMANDIR}/man1
	install -m 644 icc11/man/en_US/man1/tselect_c.1 ${PREFIX}/${PKGMANDIR}/man1

ins-doc:
	install -m 755 -d ${PREFIX}/share/doc/icc11 && \
	( cd icc11/Documentation && find . ! -type f | \
		pax -rw -pp ${PREFIX}/share/doc/icc11 )

ins-examples:
	install -m 755 -d ${PREFIX}/share/examples/icc11 && \
	( cd icc11/Samples && find . ! -type f | \
		pax -rw -pp ${PREFIX}/share/examples/icc11 )

ins-so:
	find icc11/lib -type f | grep  -w so | pax -rw -pp ${PREFIX}

ins-lib:
	find icc11/lib -type f | grep -vw so | pax -rw -pp ${PREFIX}

ins-misc:
	find icc11/bin icc11/perf_headers icc11/substitute_headers -type f | \
	pax -rw -pp ${PREFIX} && \
	( cd ${PREFIX}/icc11/bin && chmod 755 icc && ln -s icc icpc )

ins-include:
	find icc11/include -type f ! -name *.orig | pax -rw -pp ${PREFIX}

ins-bsd: libicc11bsd.a
	install -m 644 libicc11bsd.a ${PREFIX}/icc11/lib/${ICC_ARCH}
	install -m 755 -d ${PREFIX}/icc11/libexec
	install -m 644 icc11/libexec/sh-dryrun.awk ${PREFIX}/icc11/libexec
	install -m 644 icc11/libexec/print-dryrun.awk ${PREFIX}/icc11/libexec
	install -m 644 icc11/libexec/transform-dryrun.awk ${PREFIX}/icc11/libexec

.PHONY: install-linux install-netbsd ins-common ins-so ins-doc ins-man ins-examples ins-lib ins-misc ins-include ins-libicc11bsd
