# $NetBSD: Makefile,v 1.2 2011/04/17 11:38:32 cheusov Exp $
#

DISTNAME=	parallel-20110322
CATEGORIES=	parallel
MASTER_SITES=	ftp://ftp.gnu.org/gnu/parallel/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://savannah.gnu.org/projects/parallel/
COMMENT=	Build and execute shell commands in parallel
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl:run

REPLACE_PERL+=	src/parallel src/niceload src/sem src/sem.pod src/sql

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none

DOCDIR=		${PREFIX}/share/doc/parallel
DOCFILES=	NEWS README COPYING
post-install:
.for i in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${DOCDIR}/
.endfor

.include "../../mk/bsd.pkg.mk"
