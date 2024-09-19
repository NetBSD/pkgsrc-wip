# $NetBSD$

GITHUB_PROJECT=	FreeVRRPd
DISTNAME=	freevrrpd-1.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=gvnn3/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	BSD licensed implementation of the VRRP protocol (V2 and V3)
LICENSE=	2-clause-bsd

# Instead of -Wno-error=pointer-sign -Wno-error=char-subscripts
#            -Wno-error=unused-but-set-variable etc.
BUILDLINK_TRANSFORM+=	rm:-Werror

DOCDIR=		share/doc/freevrrpd
EGDIR=		share/examples/freevrrpd
CONF_FILES=	${PREFIX}/${EGDIR}/freevrrpd.conf ${PKG_SYSCONFDIR}/freevrrpd.conf

RCD_SCRIPTS=			freevrrpd
RCD_SCRIPT_SRC.freevrrpd=	${FILESDIR}/freevrrpd.sh

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths
SUBST_FILES.fix-paths=		freevrrpd.8
SUBST_VARS.fix-paths+=		PREFIX PKG_SYSCONFDIR

INSTALLATION_DIRS=		sbin ${PKGMANDIR}/man8 ${EGDIR} ${DOCDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freevrrpd ${DESTDIR}${PREFIX}/sbin/freevrrpd
	${INSTALL_DATA} ${WRKSRC}/freevrrpd.conf.sample \
		${DESTDIR}${PREFIX}/${EGDIR}/freevrrpd.conf
	${INSTALL_DATA} ${WRKSRC}/ABOUTCISCOPATENT \
		${DESTDIR}${PREFIX}/${DOCDIR}/ABOUTCISCOPATENT
	${INSTALL_MAN} ${WRKSRC}/freevrrpd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
