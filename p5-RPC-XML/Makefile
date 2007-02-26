# $NetBSD: Makefile,v 1.2 2007/02/26 05:19:01 netcap Exp $

DISTNAME=	RPC-XML-0.59
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=RPC/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://www.blackperl.com/RPC::XML/
COMMENT=	XML-RPC client and server library for Perl

DEPENDS+=	p5-XML-Parser>=2.31:../../textproc/p5-XML-Parser
DEPENDS+=	p5-PathTools>=0.8:../../devel/p5-PathTools
DEPENDS+=	p5-libwww>=5.801:../../www/p5-libwww

USE_TOOLS+=gmake

PERL5_PACKLIST=	auto/RPC/XML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
