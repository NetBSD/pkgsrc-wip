# $NetBSD: Makefile,v 1.1.1.1 2008/08/16 12:07:00 leot1990 Exp $
#

DISTNAME=	Config-Simple-4.59
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SH/SHERZODR/}

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/dist/Config-Simple/
COMMENT=	Simple configuration file class

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Config/Simple/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
