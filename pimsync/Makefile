# $NetBSD$

DISTNAME=	pimsync-v0.5.11
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	time net
# doesn't allow direct downloads
#MASTER_SITES=	https://git.sr.ht/~whynothugo/pimsync/archive/
DISTFILES=	${DEFAULT_DISTFILES} digest_auth_rs-3383b863d1d770bbab1d6690929a7f6a3e8c1a93.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pimsync.whynothugo.nl/index.html
COMMENT=	Synchronise calendars and contacts between different storages
LICENSE=	eupl-v1.2

RUST_REQ+=	1.88.0

# yes, including PKGREVISION
MAKE_ENV+=	PIMSYNC_VERSION=${PKGVERSION}

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	${PKGMANDIR}/man5
INSTALLATION_DIRS+=	${PKGMANDIR}/man7
INSTALLATION_DIRS+=	share/zsh/site-functions

post-install:
	${INSTALL_DATA} ${WRKSRC}/pimsync.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/pimsync.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKSRC}/pimsync-migration.7 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7
	${INSTALL_DATA} ${WRKSRC}/contrib/_pimsync ${DESTDIR}${PREFIX}/share/zsh/site-functions

.include "cargo-depends.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
