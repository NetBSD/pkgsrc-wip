# $NetBSD: Makefile,v 1.1.1.1 2004/04/04 21:29:20 roelants Exp $
#

DISTNAME=		rt-3.0.10
CATEGORIES=		devel
MASTER_SITES=		http://download.bestpractical.com/pub/rt/release/

MAINTAINER=		dieter.NetBSD@pandora.be
HOMEPAGE=		http://bestpractical.com/rt/
COMMENT=		Industrial-grade ticketing system

DEPENDS+=	p5-Params-Validate>=0.02:../../devel/p5-Params-Validate
DEPENDS+=	p5-Cache-Cache>=1.02:../../devel/p5-Cache-Cache
DEPENDS+=	p5-HTML-Mason>=1.16:../../www/p5-HTML-Mason
DEPENDS+=	p5-MLDBM>=2.01:../../databases/p5-MLDBM
DEPENDS+=	p5-FreezeThaw>=0.43:../../devel/p5-FreezeThaw
DEPENDS+=	p5-Digest-MD5>=2.27:../../security/p5-Digest-MD5
DEPENDS+=	p5-Apache-Session>=1.53:../../www/p5-Apache-Session
DEPENDS+=	p5-HTML-Tree>=3.18:../../www/p5-HTML-Tree
DEPENDS+=	p5-HTML-Format>=2.03:../../www/p5-HTML-Format
DEPENDS+=	p5-libwww>=5.76:../../www/p5-libwww
DEPENDS+=	p5-libapreq>=1.2:../../www/p5-libapreq
DEPENDS+=	p5-Apache-DBI>=0.92:../../databases/p5-Apache-DBI
DEPENDS+=	p5-DBD-postgresql>=1.22:../../databases/p5-DBD-postgresql
DEPENDS+=	p5-DBI>=1.37:../../databases/p5-DBI
DEPENDS+=	p5-Test-Inline>=0.15:../../devel/p5-Test-Inline
DEPENDS+=	p5-Class-ReturnValue>=0.40:../../devel/p5-Class-ReturnValue
DEPENDS+=	p5-DBIx-SearchBuilder>=0.97:../../databases/p5-DBIx-SearchBuilder
DEPENDS+=	p5-Text-Template>=1.43:../../textproc/p5-Text-Template
DEPENDS+=	p5-File-Spec>=0.8:../../devel/p5-File-Spec
DEPENDS+=	p5-HTML-Parser>=3.35:../../www/p5-HTML-Parser
DEPENDS+=	p5-Net>=1.15:../../net/p5-Net
DEPENDS+=	p5-Log-Dispatch>=2.0:../../devel/p5-Log-Dispatch
DEPENDS+=	p5-Locale-Maketext-Lexicon>=0.32:../../wip/p5-Locale-Maketext-Lexicon
DEPENDS+=	p5-Locale-Maketext-Fuzzy>=0.02:../../wip/p5-Locale-Maketext-Fuzzy
DEPENDS+=	p5-MIME-tools>=5.411.1:../../mail/p5-MIME-tools
DEPENDS+=	p5-MailTools>=1.57:../../mail/p5-MailTools
DEPENDS+=	p5-Net>=1.15:../../net/p5-Net
DEPENDS+=	p5-Text-Wrapper>=1.0:../../textproc/p5-Text-Wrapper
DEPENDS+=	p5-Time>=101.062101:../../time/p5-Time
DEPENDS+=	p5-Term-ReadKey>=2.21:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Text-Autoformat>=1.04:../../textproc/p5-Text-Autoformat
DEPENDS+=	p5-Text-Quoted>=1.5:../../wip/p5-Text-Quoted
DEPENDS+=	p5-Regexp-Common>=2.113:../../textproc/p5-Regexp-Common
DEPENDS+=	p5-Test-Inline>=0.15:../../devel/p5-Test-Inline
DEPENDS+=	p5-WWW-Mechanize>=0.72:../../wip/p5-WWW-Mechanize

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

PERL5_REQD+=	5.8

RT_DB_TYPE?=		Pg

# should depend on RT_DB_TYPE
DB_DBA?=		postgres
RT_DB_DATABASE?=	rt3
RT_DB_HOST?=		localhost
RT_DB_USER?=		rt_user
RT_DB_PASS?=		rt_pass

RT_GROUP?=		rt
RT_LOCAL_PATH?=		# not defined

#PKG_GROUPS=		${RT_GROUP}

CONFIGURE_ENV+=		customdir=${RT_LOCAL_PATH}

CONFIGURE_ARGS+=	--enable-layout=pkgsrc
CONFIGURE_ARGS+=	--with-rt-group=${RT_GROUP}
CONFIGURE_ARGS+=	--with-db-type=${RT_DB_TYPE}
CONFIGURE_ARGS+=	--with-db-host=${RT_DB_HOST}
CONFIGURE_ARGS+=	--with-db-dba=${DB_DBA}
CONFIGURE_ARGS+=	--with-db-database=${RT_DB_DATABASE}
CONFIGURE_ARGS+=	--with-db-rt-user=${RT_DB_USER}
CONFIGURE_ARGS+=	--with-db-rt-pass=${RT_DB_PASS}
CONFIGURE_ARGS+=	--with-web-user=${APACHE_USER}
CONFIGURE_ARGS+=	--with-web-group=${APACHE_GROUP}

MESSAGE_SUBST+=		HOMEPAGE=${HOMEPAGE}
MESSAGE_SUBST+=		RT_GROUP=${RT_GROUP}

.include "../../mk/bsd.pkg.mk"
