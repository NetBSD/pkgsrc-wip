SCRIPTS=	pkg_status

FILES=		NEWS
FILESDIR=	${PREFIX}/share/doc/pkg_status

CLEANFILES=	pkg_status

PKG_INFO_CMD?=	pkg_info
PACKAGES?=	/usr/pkgsrc/packages

pkg_status: pkg_status.in
	sed -e 's,@PKG_INFO_CMD@,${PKG_INFO_CMD},' \
	    -e 's,@PACKAGES@,${PACKAGES},' \
	    ${.ALLSRC} > ${.TARGET}

.include <bsd.prog.mk>
