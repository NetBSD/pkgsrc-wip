# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:35 thomasklausner Exp $
fsharp_version=	3.1.1
DISTNAME=	fsharp-${fsharp_version}
CATEGORIES=	lang
MASTER_SITES=	-https://github.com/fsharp/fsharp/archive/${fsharp_version}.tar.gz
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fsharp.org/
COMMENT=	Fsharp compiler and interpreter
LICENSE=	apache-2.0

USE_TOOLS+=	autoconf gmake
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	NO

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
