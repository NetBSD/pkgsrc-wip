# $NetBSD: Makefile,v 1.8 2012/09/24 17:14:26 asau Exp $
#

DISTNAME=		bashdb-3.1-0.06
PKGNAME=		bashdb-3.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bashdb/}

MAINTAINER=		splitscreen@users.sourceforge.net
HOMEPAGE=		http://sourceforge.net/projects/bashdb/
COMMENT=		The Bash debugger project
LICENSE=		gnu-gpl-v2

DEPENDS+=		bash-[0-9]*:../../shells/bash

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

USE_LANGUAGES=		c c++ fortran77

INFO_FILES=		yes

.include "../../mk/bsd.pkg.mk"
