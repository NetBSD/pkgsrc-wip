# $NetBSD: Makefile,v 1.2 2012/10/04 10:45:28 asau Exp $

DISTNAME=	Gtk2-Spell-1.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TS/TSCH/}

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://search.cpan.org/~tsch/Gtk2-Spell/
COMMENT=	Bindings for GtkSpell with Gtk2
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

DEPENDS+=	p5-ExtUtils-Depends>=0.300:../../devel/p5-ExtUtils-Depends
DEPENDS+=	p5-ExtUtils-PkgConfig>=1.00:../../devel/p5-ExtUtils-PkgConfig

PERL5_PACKLIST=	auto/Gtk2/Spell/.packlist

.include "../../x11/p5-gtk2/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
