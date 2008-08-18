# $NetBSD: Makefile,v 1.2 2008/08/18 23:14:58 leot1990 Exp $
#

DISTNAME=	POD2-IT-0.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EN/ENRYS/}

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://pod2it.sourceforge.net/
COMMENT=	Italian translation of Perl core documentation

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/POD2/IT/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
