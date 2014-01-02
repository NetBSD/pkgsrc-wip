# $NetBSD: Makefile,v 1.1 2014/01/02 21:37:54 nros Exp $
fsharp_version=	3.1.1
DISTNAME=	fsharp-${fsharp_version}
CATEGORIES=	lang
MASTER_SITES=	-https://github.com/fsharp/fsharp/archive/${fsharp_version}.tar.gz
FETCH_USING=	curl
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fsharp.org/
COMMENT=	Fsharp compiler and interpreter
LICENSE=	apache-2.0

USE_TOOLS+=	autoconf gmake
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	NO

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
