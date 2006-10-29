# $NetBSD: Makefile,v 1.4 2006/10/29 08:32:38 shattered Exp $
#

DISTNAME=		bashdb-3.1-0.06
PKGNAME=		bashdb-3.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bashdb/}

MAINTAINER=		splitscreen@users.sourceforg.net
HOMEPAGE=		http://sourceforge.net/projects/bashdb/
COMMENT=		The Bash debugger project

DEPENDS+=		bash-[0-9]*:../../shells/bash

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

USE_LANGUAGES=		c c++ fortran

INFO_FILES=		yes

.include "../../mk/bsd.pkg.mk"
