# $NetBSD$

DISTNAME=	cu-1.0
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GITHUB:=aalm/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/aalm/cu/
COMMENT=	serial terminal emulator
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes

USE_TOOLS+=	automake autoconf autoreconf pkg-config

pre-configure:
	cd ${WRKSRC} && sh autogen.sh

.include "../../devel/libevent/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=	libevent>=2.0.10
.include "../../mk/bsd.pkg.mk"
