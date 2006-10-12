# $NetBSD: Makefile,v 1.3 2006/10/12 21:13:41 shattered Exp $
#

DISTNAME=		bashdb-3.1-0.06
PKGNAME=                bashdb-3.1
CATEGORIES=	        devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bashdb/}

MAINTAINER=		splitscreen@users.sourceforg.net
HOMEPAGE=		http://sourceforge.net/projects/bashdb/
COMMENT=		The Bash debugger project

DEPENDS+=		bash-[0-9]*:../../shells/bash

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=          yes

USE_LANGUAGES+=         c++
USE_LANGUAGES+=         fortran
USE_LANGUAGES+=         c

INFO_FILES=             yes

.include "../../mk/bsd.pkg.mk"
