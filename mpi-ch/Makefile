# $NetBSD: Makefile,v 1.6 2008/04/15 19:32:16 asau Exp $

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

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/${PKGNAME_NOREV}
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/${PKGNAME_NOREV}
CONFIGURE_ARGS+=	--with-htmldir=${PREFIX}/share/doc/${PKGNAME_NOREV}/html

USE_TOOLS+=		perl:run

REPLACE_PYTHON+=	src/pm/mpd/test/test1.py
REPLACE_PYTHON+=	src/pm/mpd/test/test2.py
REPLACE_PYTHON+=	src/pm/mpd/test/test3.py
REPLACE_PYTHON+=	src/pm/mpd/test/tests.py
REPLACE_PYTHON+=	src/pm/mpd/test/test4.py
REPLACE_PYTHON+=	src/pm/mpd/test/testroot.py
REPLACE_PYTHON+=	src/pm/mpd/test/test5.py
REPLACE_PYTHON+=	src/pm/mpd/mpdcleanup.py
REPLACE_PYTHON+=	src/pm/mpd/mpdlistjobs.py
REPLACE_PYTHON+=	src/pm/mpd/mpdhelp.py
REPLACE_PYTHON+=	src/pm/mpd/mpdringtest.py
REPLACE_PYTHON+=	src/pm/mpd/mpdwrapcli.py
REPLACE_PYTHON+=	src/pm/mpd/mpdboot.py
REPLACE_PYTHON+=	src/pm/mpd/mpdlib.py
REPLACE_PYTHON+=	src/pm/mpd/newboot.py
REPLACE_PYTHON+=	src/pm/mpd/mpdsigjob.py
REPLACE_PYTHON+=	src/pm/mpd/mpdkilljob.py
REPLACE_PYTHON+=	src/pm/mpd/newkmpds.py
REPLACE_PYTHON+=	src/pm/mpd/mpdchkpyver.py
REPLACE_PYTHON+=	src/pm/mpd/mpiexec.py
REPLACE_PYTHON+=	src/pm/mpd/mpdallexit.py
REPLACE_PYTHON+=	src/pm/mpd/mpdtrace.py
REPLACE_PYTHON+=	src/pm/mpd/mpdgdbdrv.py
REPLACE_PYTHON+=	src/pm/mpd/mpdexit.py
REPLACE_PYTHON+=	src/pm/mpd/mpdman.py
REPLACE_PYTHON+=	src/pm/mpd/mpdcheck.py
REPLACE_PYTHON+=	src/pm/mpd/mpd.py
REPLACE_PYTHON+=	src/pm/mpd/mtv_setup.py

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
