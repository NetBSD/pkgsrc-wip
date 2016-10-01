# $NetBSD$

DISTNAME=	universalcodegrep-0.2.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=gvansickle/}
GITHUB_PROJECT=	ucg
#GITHUB_RELEASE=	${PKGVERSION_NOREV}
GITHUB_TAG=	038e498679dcce932469089ff794176e44d7024c

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gvansickle/ucg/
COMMENT=	Extremely fast grep-like tool for searching source code
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake pkg-config

NOT_PAX_MPROTECT_SAFE=	bin/ucg

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../lang/python/application.mk"
.include "../../devel/argp/buildlink3.mk"
BUILDLINK_API_DEPENDS.pcre2+=	pcre2>=10.22nb1
.include "../../devel/pcre2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
