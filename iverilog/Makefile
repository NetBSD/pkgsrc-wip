# $NetBSD$

DISTNAME=	iverilog-10.0
CATEGORIES=	lang devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=steveicarus/}
GITHUB_TAG=	v${PKGVERSION_NOREV:S/./_/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://iverilog.icarus.com/
COMMENT=	Verilog simulation and synthesis tool
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

USE_TOOLS+=	autoconf gmake bison

GNU_CONFIGURE=	yes

pre-configure:
	${RUN} cd ${WRKSRC} && autoconf

.include "../../mk/bsd.pkg.mk"
