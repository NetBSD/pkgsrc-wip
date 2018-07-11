# $NetBSD$

# this should use a Makefile.common to share the DISTNAME
DISTNAME=	gnats-4.2.0
PKGNAME=	send-pr-${GNATS_VERSION}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=gnats/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gnats/
COMMENT=	Problem reporting tool for GNATS bug-tracker
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/gnats-${GNATS_VERSION}
GNATS_VERSION=	${DISTNAME:S/gnats-//}

CONFLICTS+=		gnats-[0-9]* arla-[0-9]*

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

CONFIGURE_ENV+=		GNATS_ROOT=${PKG_SYSCONFDIR}

# Stop the configuration program from pulling installation information
# in from the standard NetBSD send-pr program
CONFIGURE_ENV+=		SEND_PR=/dev/null

BUILD_MAKE_FLAGS+=	MAKEINFO=makeinfo\ --no-split

PKG_SYSCONFSUBDIR=	gnats

EGDIR=			share/examples/gnats

MAKE_DIRS+=		${PKG_SYSCONFDIR}
CONF_FILES=		${PREFIX}/${EGDIR}/send-pr.NetBSD.conf \
			${PKG_SYSCONFDIR}/send-pr.conf
CONF_FILES+=		${PREFIX}/${EGDIR}/netbsd-template \
			${PKG_SYSCONFDIR}/netbsd-template

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		post-patch
SUBST_MESSAGE.fix-paths=	Fixing paths
SUBST_FILES.fix-paths+=		send-pr.NetBSD.conf
SUBST_SED.fix-paths+=		-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8
INSTALLATION_DIRS+=	share/gnats/dist ${EGDIR}

post-extract:
.for f in send-pr.NetBSD.conf netbsd-template
	cp ${FILESDIR}/${f} ${WRKSRC}
.endfor

do-build:
	cd ${WRKSRC}/doc/man && env ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS}
	cd ${WRKSRC}/gnats && env ${MAKE_ENV} ${MAKE_PROGRAM} \
		${BUILD_MAKE_FLAGS} install-sid send-pr

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gnats/install-sid \
		${DESTDIR}${PREFIX}/bin/install-sid
	${INSTALL_SCRIPT} ${WRKSRC}/gnats/send-pr ${DESTDIR}${PREFIX}/bin/send-pr
	${INSTALL_MAN} ${WRKSRC}/doc/man/send-pr.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/send-pr.1
	${INSTALL_MAN} ${WRKSRC}/doc/man/install-sid.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/install-sid.8
	${INSTALL_DATA} ${WRKSRC}/INSTALL \
		${DESTDIR}${PREFIX}/share/gnats/dist/INSTALL.send-pr
	${INSTALL_DATA} ${FILESDIR}/netbsd-categories \
		${DESTDIR}${PREFIX}/share/gnats/netbsd
	${INSTALL_DATA} ${WRKSRC}/netbsd-template ${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/gnats/send-pr.conf ${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/send-pr.NetBSD.conf ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../mk/bsd.pkg.mk"
