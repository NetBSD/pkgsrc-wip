# $NetBSD: Makefile,v 1.1.1.1 2003/07/13 03:42:23 schnoebe Exp $
#

DISTNAME=	DBI-Shell-11.9
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dbi
CATEGORIES=	wip databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBI/}

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://www.perldoc.com/perl5.6.1/lib/DBI/Shell.html
COMMENT=	Interactive command Shell for the Perl DBI

DEPENDS+=	p5-DBI:../../databases/p5-DBI
DEPENDS+=	p5-IO-Tee:../../wip/p5-IO-Tee
DEPENDS+=	p5-Text-Reform:../../wip/p5-Text-Reform
# DEPENDS+=	p5-IO-Tee:../../devel/p5-IO-Tee
# DEPENDS+=	p5-Text-Reform:../../text/p5-Text-Reform

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBI/Shell/.packlist

.include "../../databases/p5-DBI/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
