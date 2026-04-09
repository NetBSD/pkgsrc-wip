# $NetBSD$

DISTNAME=	pimsync-v0.5.7
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	time net
# doesn't allow direct downloads
#MASTER_SITES=	https://git.sr.ht/~whynothugo/pimsync/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pimsync.whynothugo.nl/index.html
COMMENT=	Synchronise calendars and contacts between different storages
LICENSE=	eupl-v1.2

HASHIFY_REV=	242c78f03ce1eea42c273912395e880c72d69b23
HASHIFY_TGZ=	hashify-${HASHIFY_REV}.tar.gz
DISTFILES=	${DEFAULT_DISTFILES} ${HASHIFY_TGZ}

SITES.${HASHIFY_TGZ}=	-${MASTER_SITE_GITHUB:=WhyNotHugo/}hashify/archive/${HASHIFY_REV}.tar.gz

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
