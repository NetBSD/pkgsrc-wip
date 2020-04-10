# $NetBSD$

DISTNAME=	xbps-0.59.1
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_GITHUB:=void-linux/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://github.com/void-linux/xbps/
COMMENT=	The X Binary Package System
LICENSE=	2-clause-bsd

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONFS=		xbps.conf 00-repository-main.conf

.for f in ${CONFS}
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/xbps.d/${f}
.endfor

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 share/examples/${PKGBASE}

OWN_DIRS+=	${PKG_SYSCONFDIR}/xbps.d

USE_TOOLS+=	pkg-config gmake
GNU_CONFIGURE=	yes

post-install:
	${MKDIR} ${DESTDIR}${EGDIR} &&\
	for f in ${CONFS}; do \
	  ${MV} ${DESTDIR}${PREFIX}/share/xbps.d/$${f} ${DESTDIR}${EGDIR}; \
	done

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
