# $NetBSD$

DISTNAME=	dma-${GITHUB_TAG}
PKGNAME=	dma-0.11
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=corecode/}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://github.com/corecode/dma
COMMENT=	The DragonFly Mail Agent
LICENSE=	modified-bsd

GITHUB_PROJECT=	dma
GITHUB_TAG=	v0.11

BUILD_DEFS+=		VARBASE

PKG_SYSCONFSUBDIR=	dma
EGDIR=			${PREFIX}/share/exmaples/${PKGBASE}

USE_TOOLS+=	flex yacc
LDFLAGS.SunOS+=	-lsocket -lnsl

NO_CONFIGURE=	yes
USE_LANGUAGES=	c

.include "../../mk/bsd.prefs.mk"

DMA_GROUP?=	dma
DMA_ROOT_USER?=	dma
PKG_GROUPS=	${DMA_GROUP}
PKG_USERS=	${DMA_ROOT_USER}:${DMA_GROUP}

CFLAGS+=	-DHAVE_GETPROGNAME
CFLAGS+=	-DHAVE_STRLCPY
CFLAGS+=	-DLIBEXEC_PATH=${PREFIX}/libexec
CFLAGS+=	-DDMA_GROUP=\"${DMA_GROUP}\"
CFLAGS+=	-DDMA_ROOT_USER=\"${DMA_ROOT_USER}\"

MAKE_ENV+=	CONFDIR=${PKG_SYSCONFDIR}

MAKE_FLAGS=	"LIBEXEC=${PREFIX}/libexec"
MAKE_FLAGS+=	"MAN=${PREFIX}/${PKGMANDIR}"

INSTALLATION_DIRS=	${EGDIR}

CONF_FILES=	${EGDIR}/dma.conf ${PKG_SYSCONFDIR}/dma.conf
CONF_FILES+=	${EGDIR}/auth.conf ${PKG_SYSCONFDIR}/auth.conf

OWN_DIRS=	${VARBASE}/spool/dma
OWN_DIRS_PERMS=	${VARBASE}/spool/dma ${DMA_ROOT_USER} ${DMA_GROUP} 750

post-install:
	${INSTALL_DATA} ${WRKSRC}/dma.conf ${DESTDIR}${EGDIR}/dma.conf
	${INSTALL_DATA} ${WRKSRC}/auth.conf ${DESTDIR}${EGDIR}/auth.conf

.include "../../mk/bsd.pkg.mk"
