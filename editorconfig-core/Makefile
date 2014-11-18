# $NetBSD: Makefile,v 1.3 2014/11/18 12:24:48 nros Exp $

DISTNAME=	editorconfig-core-c-0.12.0
PKGNAME=	${DISTNAME:S/c-//}
CATEGORIES=	devel
MASTER_SITES=	http://downloads.sf.net/project/editorconfig/EditorConfig-C-Core/${PKGVERSION}/source/

MAINTAINER=	nros@users.sourceforge.net
HOMEPAGE=	http://www.editorconfig.org/
COMMENT=	Editorconfig C library
LICENSE=	2-clause-bsd

USE_CMAKE= 	yes

.include "options.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
