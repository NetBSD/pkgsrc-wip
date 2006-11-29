# $NetBSD: Makefile,v 1.1 2006/11/29 14:16:39 cheusov Exp $
#

DISTNAME=		Net-Dict-2.07
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		net textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		cheusov@tut.by
HOMEPAGE=		http://www.cpan.org/modules/by-module/Net/
COMMENT=		Client API for the DICT protocol defined in RFC2229.

NO_BUILD=		yes
PKG_INSTALLATION_TYPES= overwrite pkgviews
PERL5_PACKLIST=		auto/Net/Dict/.packlist

DEPENDS+=		p5-AppConfig-[0-9]*:../../devel/p5-AppConfig
DEPENDS+=		p5-Tk-[0-9]*:../../x11/p5-Tk

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
