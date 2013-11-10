# $NetBSD: Makefile,v 1.1 2013/11/10 21:04:48 nros Exp $

DISTNAME=	editorconfig-core-c-0.11.5
PKGNAME=	editorconfig-core-0.11.5
CATEGORIES=	devel
MASTER_SITES=	http://downloads.sf.net/project/editorconfig/EditorConfig-C-Core/${PKGVERSION}/source/

MAINTAINER=	nros@users.sourceforge.net
HOMEPAGE=	http://www.editorconfig.org/
COMMENT=	Editorconfig C library
LICENSE=	2-clause-bsd

USE_CMAKE= 	yes

CMAKE_ARGS+=	-DPKGMANDIR=${PKGMANDIR}

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
