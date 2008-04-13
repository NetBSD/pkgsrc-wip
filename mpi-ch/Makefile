# $NetBSD: Makefile,v 1.3 2008/04/13 15:15:36 asau Exp $

DISTNAME=	mpich2-1.0.7
CATEGORIES=	parallel
MASTER_SITES=	http://www.mcs.anl.gov/research/projects/mpich2/downloads/tarballs/

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.mcs.anl.gov/research/projects/mpich2/
COMMENT=	Open source MPI and MPI-2 implementation from Univ. of Chicago

CONFLICTS=	musicpd-[0-9]* mpich-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++ fortran

.include "../../mk/bsd.pkg.mk"
