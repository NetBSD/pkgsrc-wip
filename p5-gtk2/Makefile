# $NetBSD: Makefile,v 1.1.1.1 2003/04/24 16:37:30 bmeurer Exp $

DISTNAME=		Gtk2-Perl-0.12
PKGNAME=		p5-gtk2-0.12
CATEGORIES=		x11 perl5
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtk2-perl/}

DEPENDS+=		perl>=5.8.0:../../lang/perl58
DEPENDS+=		p5-Inline>=0.43:../../devel/p5-Inline

MAINTAINER=		benedikt.meurer@unix-ag.uni-siegen.de
HOMEPAGE=		http://gtk2-perl.sourceforge.net/
COMMENT=		Perl bindings for GTK+ 2.0

USE_BUILDLINK2=		YES
USE_X11=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Gtk2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
