# $NetBSD: Makefile,v 1.16 2008/07/19 08:44:49 phonohawk Exp $

DISTNAME=		darcs-2.0.0rc1
CATEGORIES=		devel scm
MASTER_SITES=		http://www.darcs.net/

MAINTAINER=		matias@dotbsd.org
HOMEPAGE=		http://www.darcs.net/
COMMENT=		Distributed revision control system

BUILD_DEPENDS+=		latex2html>=2002.2.1nb3:../../textproc/latex2html

TEX_DEPMETHOD=		build
USE_TOOLS+=		gmake
MAKE_FILE=		GNUmakefile
GNU_CONFIGURE=		yes

.include "../../www/curl/buildlink3.mk"
.include "../../lang/ghc/buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# To avoid Darwin problem
CPP_PRECOMP_FLAGS=
