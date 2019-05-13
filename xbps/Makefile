# $NetBSD$

DISTNAME=	xbps-0.53
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_GITHUB:=void-linux/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://github.com/void-linux/xbps/
COMMENT=	The X Binary Package System
LICENSE=	2-clause-bsd

EGDIR=          ${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=     ${EGDIR}/xbps.conf.example \
                  ${PKG_SYSCONFDIR}/xbps.d/xbps.conf \
                ${EGDIR}/00-repository-main.conf.example \
                  ${PKG_SYSCONFDIR}/xbps.d/00-repository-main.conf

OWN_DIRS+=      ${PKG_SYSCONFDIR}/${PKGBASE}

USE_TOOLS+=	pkg-config gmake
GNU_CONFIGURE=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/share && \
	  ${MKDIR} examples/xbps && \
	  ${MV} xbps.d/xbps.conf examples/xbps/xbps.conf.example && \
	  ${MV} xbps.d/00-repository-main.conf examples/xbps/00-repository-main.conf.example && \
	  ${RMDIR} xbps.d

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
