# $NetBSD$

GITHUB_PROJECT=	mummer
DISTNAME=	mummer-4.0.0rc1
PKGNAME=	mummer4-4.0.0.20201002
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=mummer4/}
GITHUB_RELEASE=	v4.0.0rc1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mummer4/mummer/
COMMENT=	Versatile alignment tool for DNA and protein sequences
LICENSE=	artistic

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake perl:run pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_ENV+=	PERL=${PERL5}

PKGCONFIG_OVERRIDE+=	mummer.pc.in

.include "../../mk/bsd.pkg.mk"
