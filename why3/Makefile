# $NetBSD: Makefile,v 1.1 2015/08/14 23:11:53 jihbed Exp $

DISTNAME=	why3-1.4.0
CATEGORIES=	devel
MASTER_SITES=	https://why3.gitlabpages.inria.fr/releases/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://why3.lri.fr/
COMMENT=	Platform for deductive program verification
LICENSE=	gnu-lgpl-v2.1

#DEPENDS+=	frama-c-[0-9]*:../../devel/frama-c
DEPENDS+=	menhir-[0-9]*:../../devel/menhir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

#CONFIGURE_ARGS+=		--enable-frama-c
CONFIGURE_ARGS+=		--disable-ide

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
