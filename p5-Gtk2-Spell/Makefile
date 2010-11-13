# $NetBSD: Makefile,v 1.1.1.1 2010/11/13 12:52:04 ryo-on Exp $
#

DISTNAME=	Gtk2-Spell-1.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/ML/MLEHMANN/}

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://search.cpan.org/~mlehmann/Gtk2-Spell-1.03/
COMMENT=	Bindings for GtkSpell with Gtk2
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config

DEPENDS+=	p5-ExtUtils-Depends>=0.300:../../devel/p5-ExtUtils-Depends
DEPENDS+=	p5-ExtUtils-PkgConfig>=1.00:../../devel/p5-ExtUtils-PkgConfig

PERL5_PACKLIST=	auto/Gtk2/Spell/.packlist

.include "../../x11/p5-gtk2/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
