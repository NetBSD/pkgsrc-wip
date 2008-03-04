# $NetBSD: Makefile,v 1.1.1.1 2008/03/04 21:56:43 airhead Exp $
#

DISTNAME=	lire-2.0.2.99.2
CATEGORIES=	sysutils
MASTER_SITES=	http://download.logreport.org/pub/cvs-snapshots/
#LICENSE=	gnu-gpl-v2

MAINTAINER=	airhead@users.sf.net
HOMEPAGE=	http://download.logreport.org/pub/cvs-snapshots/
COMMENT=	Log analyzing tool

DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=	p5-DBD-SQLite2-[0-9]*:../../databases/p5-DBD-SQLite2
DEPENDS+=	p5-Curses-[0-9]*:../../devel/p5-Curses
DEPENDS+=	p5-Curses-UI-[0-9]*:../../devel/p5-Curses-UI
DEPENDS+=	p5-Locale-libintl-[0-9]*:../../misc/p5-Locale-libintl
DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl

SUBST_CLASSES+=		3pm
SUBST_STAGE.3pm=	pre-configure
SUBST_SED.3pm=		-e "s,\\.3pm,\\.3,g"
SUBST_SED.3pm+=		-e "s,--section=3pm,--section=3,g"
SUBST_FILES.3pm=	all/etc/Makefile.in
SUBST_FILES.3pm+=	all/lib/Lire/Config/Makefile.am
SUBST_FILES.3pm+=	all/lib/Lire/Config/Makefile.in
SUBST_FILES.3pm+=	all/lib/Lire/Makefile.am
SUBST_FILES.3pm+=	all/lib/Lire/Makefile.in
SUBST_FILES.3pm+=	all/lib/Lire/ChartTypes/Makefile.am
SUBST_FILES.3pm+=	all/lib/Lire/ChartTypes/Makefile.in
SUBST_FILES.3pm+=	all/lib/Lire/Report/Makefile.am
SUBST_FILES.3pm+=	all/lib/Lire/Report/Makefile.in
SUBST_FILES.3pm+=	all/lib/Lire/OutputFormats/Makefile.am
SUBST_FILES.3pm+=	all/lib/Lire/OutputFormats/Makefile.in
SUBST_FILES.3pm+=	all/lib/Lire/ReportParser/Makefile.am
SUBST_FILES.3pm+=	all/lib/Lire/ReportParser/Makefile.in
SUBST_FILES.3pm+=	all/lib/Lire/SQLExt/Makefile.am
SUBST_FILES.3pm+=	all/lib/Lire/SQLExt/Makefile.in
SUBST_FILES.3pm+=	all/lib/Lire/Test/Makefile.am
SUBST_FILES.3pm+=	all/lib/Lire/Test/Makefile.in
SUBST_FILES.3pm+=	all/lib/Lire/UI/Makefile.am
SUBST_FILES.3pm+=	all/lib/Lire/UI/Makefile.in
SUBST_FILES.3pm+=	all/lib/tests/helpers/Makefile.in
SUBST_FILES.3pm+=	all/lib/tests/Makefile.in
SUBST_FILES.3pm+=	all/lib/xml/dtd/Makefile.in
SUBST_FILES.3pm+=	all/lib/Makefile.in
SUBST_FILES.3pm+=	all/lib/config-spec/Makefile.in
SUBST_FILES.3pm+=	all/lib/Firewall/Makefile.am
SUBST_FILES.3pm+=	all/lib/Firewall/Makefile.in
SUBST_FILES.3pm+=	all/script/Makefile.in
SUBST_FILES.3pm+=	all/man/Makefile.in
SUBST_FILES.3pm+=	all/schemas/Makefile.in
SUBST_FILES.3pm+=	database/script/Makefile.in
SUBST_FILES.3pm+=	dialup/script/Makefile.in
SUBST_FILES.3pm+=	dns/script/Makefile.in
SUBST_FILES.3pm+=	dnszone/script/Makefile.in
SUBST_FILES.3pm+=	doc/Makefile.in
SUBST_FILES.3pm+=	email/script/Makefile.in
SUBST_FILES.3pm+=	extras/Time/Makefile.am
SUBST_FILES.3pm+=	extras/Time/Makefile.in
SUBST_FILES.3pm+=	firewall/script/Makefile.in
SUBST_FILES.3pm+=	firewall/lib/Makefile.am
SUBST_FILES.3pm+=	firewall/lib/Makefile.in
SUBST_FILES.3pm+=	ftp/script/Makefile.in
SUBST_FILES.3pm+=	ftp/lib/Makefile.am
SUBST_FILES.3pm+=	ftp/lib/Makefile.in
SUBST_FILES.3pm+=	include/rules.mk
SUBST_FILES.3pm+=	msgstore/script/Makefile.in
SUBST_FILES.3pm+=	msgstore/lib/Makefile.in
SUBST_FILES.3pm+=	proxy/script/Makefile.in
SUBST_FILES.3pm+=	proxy/lib/Makefile.am
SUBST_FILES.3pm+=	proxy/lib/Makefile.in
SUBST_FILES.3pm+=	spamfilter/script/Makefile.in
SUBST_FILES.3pm+=	syslog/script/Makefile.in
SUBST_FILES.3pm+=	www/script/Makefile.in

.include "../../mk/bsd.pkg.mk"
