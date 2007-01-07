# $NetBSD: Makefile,v 1.3 2007/01/07 14:21:43 cheusov Exp $
#

DISTNAME=		Net-Dict-2.07
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		net textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		cheusov@tut.by
HOMEPAGE=		http://www.cpan.org/modules/by-module/Net/
COMMENT=		Client API for the DICT protocol defined in RFC2229

PKG_INSTALLATION_TYPES= overwrite pkgviews
PERL5_PACKLIST=		auto/Net/Dict/.packlist

CONFLICTS=		dict-client-[0-9]*

DEPENDS+=		p5-AppConfig-Std-[0-9]*:../../wip/p5-AppConfig-Std
DEPENDS+=		p5-Tk-[0-9]*:../../x11/p5-Tk

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
