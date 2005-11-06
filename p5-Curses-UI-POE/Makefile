# $NetBSD: Makefile,v 1.3 2005/11/06 06:49:33 marttikuparinen Exp $

DISTNAME=	Curses-UI-POE-0.02801
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Curses/}

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Curses-UI-POE
COMMENT=	Subclass for Curses::UI that enables it to work with POE

DEPENDS+=	p5-Curses-UI>=0:../../wip/p5-Curses-UI

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Curses/UI/POE/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
