# $NetBSD: Makefile,v 1.1.1.1 2004/03/27 22:41:56 xtraeme Exp $

DISTNAME=	NetPacket-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=NetPacket/}

MAINTAINER=	david@netbsd-fr.org
COMMENT=	Modules to assemble/disassemble network packets

USE_BUILDLINK2=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/NetPacket/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
