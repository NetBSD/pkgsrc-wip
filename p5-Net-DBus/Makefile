# $NetBSD: Makefile,v 1.2 2007/07/13 07:38:03 bartoszkuzma Exp $
#

DISTNAME=	Net-DBus-0.33.4
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	wip sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://www.freedesktop.org/Software/dbus
COMMENT=	Perl bindings for the D-BUS message bus system

DEPENDS+=	p5-XML-Twig>=3.17:../../textproc/p5-XML-Twig

USE_TOOLS+=	pkg-config

PERL5_PACKLIST=	auto/Net/DBus/.packlist

.include "../../lang/perl5/module.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
