# $NetBSD: options.mk,v 1.1 2014/08/18 03:48:11 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ruby-redmine
PKG_SUPPORTED_OPTIONS=	bzr cvs darcs doc git hg imagemagick ldap markdown
PKG_SUPPORTED_OPTIONS+=	openid svn tests
PKG_SUGGESTED_OPTIONS+=	doc imagemagick markdown mysql openid

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		freetds mysql pgsql sqlite3

.include "../../mk/bsd.options.mk"

.include "../../lang/ruby/rubyversion.mk"

.if !empty(PKG_OPTIONS:Mbzr)
DEPENDS+=	bzr-[0-9]*:../../devel/bzr
.endif

.if !empty(PKG_OPTIONS:Mcvs)
DEPENDS+=	cvs-[0-9]*:../../devel/scmcvs
.endif

.if !empty(PKG_OPTIONS:Mdarcs)
DEPENDS+=	darcs-[0-9]*:../../devel/darcs
.endif

.if !empty(PKG_OPTIONS:Mdoc)
DEPENDS+=	${RUBY_PKGPREFIX}-rdoc>=2.4.2:../../devel/ruby-rdoc
DEPENDS+=	${RUBY_PKGPREFIX}-yard-[0-9]*:../../textproc/ruby-yard
.endif

.if !empty(PKG_OPTIONS:Mfreetds)
.include "../../databases/freetds/buildlink3.mk"
DEPENDS+=	${RUBY_PKGPREFIX}-tiny_tds>=0.5.1:../../databases/ruby-tiny_tds
.endif

.if !empty(PKG_OPTIONS:Mgit)
DEPENDS+=	git-base-[0-9]*:../../devel/git-base
.endif

.if !empty(PKG_OPTIONS:Mhg)
DEPENDS+=	mercurial-[0-9]*:../../devel/mercurial
.endif

.if !empty(PKG_OPTIONS:Mimagemagick)
.include "../../graphics/ImageMagick/buildlink3.mk"
DEPENDS+=	${RUBY_PKGPREFIX}-RMagick>=2.0.0:../../graphics/ruby-RMagick
.endif

.if !empty(PKG_OPTIONS:Mldap)
DEPENDS+=	${RUBY_PKGPREFIX}-net-ldap>=0.3.1:../../databases/ruby-net-ldap
.endif

.if !empty(PKG_OPTIONS:Mmarkdown)
DEPENDS+=		${RUBY_PKGPREFIX}-redcarpet>=2.3.0:../../textproc/ruby-redcarpet
OVERRIDE_GEMSPEC+=	redcarpet>=2.3.0
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
DEPENDS+=	${RUBY_PKGPREFIX}-mysql2>=0.3.11:../../databases/ruby-mysql2
DEPENDS+=	${RUBY_PKGPREFIX}-mysql>=2.8.1:../../databases/ruby-mysql
.endif

.if !empty(PKG_OPTIONS:Mopenid)
DEPENDS+=		${RUBY_PKGPREFIX}-ruby-openid>=2.3.0:../../security/ruby-ruby-openid
DEPENDS+=		${RUBY_PKGPREFIX}-rack-openid-[0-9]*:../../security/ruby-rack-openid
OVERRIDE_GEMSPEC+=	ruby-openid>=2.3.0
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
DEPENDS+=	${RUBY_PKGPREFIX}-pg>=0.11.0:../../databases/ruby-pg
.endif

.if !empty(PKG_OPTIONS:Msqlite3)
.include "../../databases/sqlite3/buildlink3.mk"
DEPENDS+=	${RUBY_PKGPREFIX}-sqlite3-[0-9]*:../../databases/ruby-sqlite3
.endif

.if !empty(PKG_OPTIONS:Msvn)
DEPENDS+=	subversion-base-[0-9]*:../../devel/subversion-base
.endif

.if !empty(PKG_OPTIONS:Mtests)
DEPENDS+=		${RUBY_PKGPREFIX}-shoulda>=3.3.2:../../devel/ruby-shoulda
DEPENDS+=		${RUBY_PKGPREFIX}-mocha>=0.14:../../devel/ruby-mocha
OVERRIDE_GEMSPEC+=	shoulda>=3.3.2
DEPENDS+=		${RUBY_PKGPREFIX}-capybara>=2.1.0:../../www/ruby-capybara
DEPENDS+=		${RUBY_PKGPREFIX}-selenium-webdriver-[0-9]*:../../www/ruby-selenium-webdriver
OVERRIDE_GEMSPEC+=	capybara>=2.1.0
.endif
