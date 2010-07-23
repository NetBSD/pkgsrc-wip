# $NetBSD: Makefile,v 1.3 2010/07/23 12:52:43 tnn2 Exp $
#

DISTNAME=	mtop-0.6.6
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mtop/}

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://mtop.sourceforge.net/
COMMENT=	Curses-based MySQL server monitor
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Curses>=0:../../devel/p5-Curses
DEPENDS+=	p5-DBD-mysql>=0:../../databases/p5-DBD-mysql
DEPENDS+=	p5-Getopt-Long>=0:../../devel/p5-Getopt-Long

PERL5_PACKLIST=	auto/mtop/.packlist
USE_LANGUAGES=	# none
MAKE_PARAMS+=	--prefix=${PREFIX}

post-extract:
		rm ${WRKSRC}/cpan2spec.pl

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
