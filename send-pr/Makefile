# $NetBSD: Makefile,v 1.18 2012/10/07 16:22:55 asau Exp $

# this should use a Makefile.common to share the DISTNAME
DISTNAME=	gnats-4.1.0
PKGNAME=	send-pr-${GNATS_VERSION}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU=gnats/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gnats/
COMMENT=	GNATS problem reporting tool
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/gnats-${GNATS_VERSION}/send-pr
GNATS_VERSION=	${DISTNAME:S/gnats-//}

CONFLICTS+=	gnats-[0-9]* arla-[0-9]*

GNU_CONFIGURE=		YES

CONFIGURE_ENV+=		GNATS_ROOT=${PKG_SYSCONFDIR}

# this stops the configuration program from pulling installation
# information in from the standard NetBSD send-pr program
CONFIGURE_ENV+=		SEND_PR=/dev/null

BUILD_MAKE_FLAGS+=	MAKEINFO=makeinfo\ --no-split
INSTALL_MAKE_FLAGS+=	INSTALL_SCRIPT=${INSTALL_SCRIPT:Q} \
			sysconfdir=${EGBASE}

AUTO_MKDIRS=		yes

EGBASE=			${PREFIX}/share/examples
EGDIR=			${EGBASE}/gnats
CONF_FILES=		${EGDIR}/send-pr.NetBSD.conf \
			${PKG_SYSCONFDIR}/gnats/send-pr.conf

MAKE_DIRS+=		${PKG_SYSCONFDIR}/gnats
#			${PKG_SYSCONFDIR}/gnats/gnats-adm

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		post-patch
SUBST_MESSAGE.fix-paths=	Fixing paths
SUBST_FILES.fix-paths=		send-pr.sh
SUBST_SED.fix-paths=		-e 's,install-sid,${PREFIX}/bin/install-sid,'
SUBST_SED.fix-paths+=		-e 's,send-pr --request-id,${PREFIX}/bin/send-pr --request-id,'

post-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/share/gnats/dist/INSTALL.send-pr
	${INSTALL_DATA} ${FILESDIR}/netbsd-categories ${DESTDIR}${PREFIX}/share/gnats/netbsd
	${INSTALL_DATA} ${FILESDIR}/send-pr.NetBSD.conf ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
