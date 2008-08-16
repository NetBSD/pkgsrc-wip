# $NetBSD: Makefile,v 1.2 2008/08/16 12:57:09 leot1990 Exp $
#

DISTNAME=	WWW-YouTube-VideoURI-0.1
PKGNAME=	p5-${DISTNAME}
CATEGORIES= www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/dist/WWW-YouTube-VideoURI/
COMMENT=	Module to determine the URI of a Flash Video file on YouTube.com

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_PACKLIST=	auto/WWW/YouTube/VideoURI/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
