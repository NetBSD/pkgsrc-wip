# $NetBSD: Makefile,v 1.3 2010/11/13 11:49:40 ryo-on Exp $
#

DISTNAME=	Net-DBus-GLib-0.33.0
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DA/DANBERR/}

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://search.cpan.org/~danberr/Net-DBus-GLib-0.33.0/
COMMENT=	Perl extension for the DBus GLib bindings
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config

DEPENDS+=	p5-Net-DBus>=0.33.2:../../net/p5-Net-DBus

PERL5_PACKLIST=	auto/Net/DBus/GLib/.packlist

.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
