# $NetBSD: Makefile,v 1.1.1.1 2010/10/24 17:10:11 cheusov Exp $
#

DISTNAME=	parallel-20100922
CATEGORIES=	parallel
MASTER_SITES=	ftp://ftp.gnu.org/gnu/parallel/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://savannah.gnu.org/projects/parallel/
COMMENT=	Build and execute shell commands in parallel

PKG_DESTDIR_SUPPORT=	user-destdir
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl:run

REPLACE_PERL+=	src/parallel src/sem src/sem.pod src/sql

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../mk/bsd.pkg.mk"
