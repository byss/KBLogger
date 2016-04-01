Pod::Spec.new do |spec|
	spec.name                 = 'KBLogger'
	spec.version              = '1.0.0'
	spec.license              = { :type => 'MIT' }
	spec.homepage             = 'https://github.com/byss/' + spec.name
	spec.authors              = { 'Kirill byss Bystrov' => 'kirrbyss@gmail.com' }
	spec.summary              = 'Simple logging proxy (logging to TTY by default).'
	spec.source               = { :git => spec.homepage + '.git', :tag => 'v' + spec.version.to_s }
	spec.requires_arc         = true
	spec.source_files         = 'KBLogger.{h,m}'

	spec.ios.deployment_target     = '4.0'
	spec.osx.deployment_target     = '10.6'
	spec.watchos.deployment_target = '2.0'
end
