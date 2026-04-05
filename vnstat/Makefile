# $NetBSD$

CONF_FILES=		${EGDIR}/vnstat.conf ${PKG_SYSCONFDIR}/vnstat.conf
CONFIGURE_ARGS+=	--disable-image-output
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
INSTALLATION_DIRS=	bin ${EGDIR} ${PKGMANDIR}/man1 \
			${PKGMANDIR}/man5 ${PKGMANDIR}/man8
RCD_SCRIPTS=		vnstat

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/vnstat.conf \
		${DESTDIR}${EGDIR}/vnstat.conf
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vnstati.1

.include "../../wip/vnstat/Makefile.common"
.include "../../mk/bsd.pkg.mk"
