# $NetBSD: Makefile,v 1.1 2015/08/14 23:11:53 jihbed Exp $

DISTNAME=	why3-0.86.1
CATEGORIES=	devel
MASTER_SITES=	https://gforge.inria.fr/frs/download.php/file/34797/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://why3.lri.fr/#overview
COMMENT=	Why3 is a platform for deductive program verification
LICENSE=	gnu-lgpl-v2.1

#DEPENDS+=	frama-c-[0-9]*:../../devel/frama-c
DEPENDS+=	menhir-[0-9]*:../../devel/menhir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

#CONFIGURE_ARGS+=		--enable-frama-c
CONFIGURE_ARGS+=		--disable-ide

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
