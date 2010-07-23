# $NetBSD: Makefile,v 1.1.1.1 2010/07/23 12:10:32 tnn2 Exp $
#

DISTNAME=	mtop-0.6.6
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mtop/}

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://mtop.sourceforge.net/
COMMENT=	Curses-based MySQL server monitor
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Curses>=0:../../devel/p5-Curses
DEPENDS+=	p5-DBD-mysql>=0:../../databases/p5-DBD-mysql
DEPENDS+=	p5-DBI>=0:../../databases/p5-DBI
DEPENDS+=	p5-Getopt-Long>=0:../../devel/p5-Getopt-Long

PERL5_PACKLIST=	auto/download/.packlist
USE_LANGUAGES=	# none

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL --prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
