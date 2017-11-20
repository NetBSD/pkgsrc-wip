# $NetBSD: Makefile,v 1.9 2017/08/01 17:40:15 wiz Exp $

DISTNAME=	${GITHUB_TAG}
GITHUB_TAG=	1.1.8
PKGNAME=	otptool-${DISTNAME}
GITHUB_PROJECT=	mod-authn-otp
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=archiecobbs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/archiecobbs/mod-authn-otp
COMMENT=	One-Time Password command line utility
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}

PKG_APACHE_ACCEPTED=	apache22

USE_LANGUAGES+=	c
HAS_CONFIGURE=	yes
#GNU_CONFIGURE=	yes
USE_TOOLS+=	autoreconf autoconf automake

REPLACE_SH+=	autogen.sh


.include "../../mk/apache.mk"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

pre-configure:
	cd ${WRKSRC} && sh ./autogen.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/otptool ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/otptool.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../www/apache22/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
